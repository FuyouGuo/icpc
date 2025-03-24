// 优秀的示例代码
#include<cstdio>
#include<algorithm>
using namespace std;
const int P=3e6;
int n,Q,x,y,k;       //x 起始节点, y结束节点
int read(){
    // 读函数
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
// 写函数
void write(int x){if (x>9) write(x/10);putchar(x%10+48);}
int node;
// ls左节点，rs右节点, mx 最大值, lmx 左节点最大值, rmx 右节点最大值, cv 表明节点状态（-1表明节点非可分配, 0 表明空闲, 1表示占用）
int ls[P],rs[P],mx[P],lmx[P],rmx[P],cv[P];
void cov(int p,int z,int k){
	cv[p]=k;
	if (k) mx[p]=lmx[p]=rmx[p]=0;
	else mx[p]=lmx[p]=rmx[p]=z;
}
void up(int p,int lz,int rz){
	int ld=ls[p],rd=rs[p];
	if (lmx[ld]==lz) lmx[p]=lz+lmx[rd]; else lmx[p]=lmx[ld];
	if (rmx[rd]==rz) rmx[p]=rz+rmx[ld]; else rmx[p]=rmx[rd];
	mx[p]=max(rmx[ld]+lmx[rd],max(mx[ld],mx[rd]));
}
void down(int p,int lz,int rz){     // 将节点按照lz, rz大小左右分割
	if (!ls[p]) ls[p]=++node;       // 左节点位置
	if (!rs[p]) rs[p]=++node;       // 右节点位置
	if (cv[p]!=-1){                 // 叶子节点
		cov(ls[p],lz,cv[p]);        // 填充左节点
		cov(rs[p],rz,cv[p]);        // 填充右节点 
		cv[p]=-1;                   // 标志非可用节点
	}
}
int ask(int p,int l,int r){
    // 查询可用的区间
	if (mx[p]==r-l+1) return l;                             // 未分配，直接返回首位
	int m=(l+r)>>1;down(p,m-l+1,r-m);                       // 按照一半划分
	if (mx[ls[p]]>=k) return ask(ls[p],l,m);                // 左子树空间大于k，左子树递归查询
	if (rmx[ls[p]]+lmx[rs[p]]>=k) return m-rmx[ls[p]]+1;    // 左子树右半边最大值+右子树左侧最大值
	return ask(rs[p],m+1,r);
}
void cover(int p,int l,int r){
    // 无内存可分配或者无内存可释放，直接返回
	if ((!k&&mx[p]==r-l+1)|| (k && !mx[p])) return;
	if (x<=l && r<=y){cov(p,r-l+1,k);return;}
	int m=(l+r)>>1;down(p,m-l+1,r-m);
	if (x<=m) cover(ls[p],l,m);
	if (y>m) cover(rs[p],m+1,r);
	up(p,m-l+1,r-m);
}
void query_it(){
	k=read();if (mx[1]<k){puts("-1");return;} 
	x=ask(1,1,n);y=x+k-1;k=1;   
	cover(1,1,n);              // 区间调整
	write(x-1);putchar('\n');
}
void release_it(){
	x=read()+1;y=x+read()-1;
	if (y>n) y=n;k=0;cover(1,1,n);
}
int main(){
	n=read();Q=read();node=1;
	mx[1]=lmx[1]=rmx[1]=n;cv[1]=0;
	for (;Q--;){
		int opt=read();
		if (opt==1) query_it();
		else release_it();
	}
}