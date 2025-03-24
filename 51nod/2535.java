import java.util.*;

// 在51nod上提交需要在类前加public
class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        List<Integer> priceList = new ArrayList<Integer>(n);
        List<Integer> sumList = new ArrayList<Integer>(n);
        for(int i = 0; i < n; i++){
            priceList.add(scan.nextInt());
        }
        Collections.sort(priceList);
        sumList.add(priceList.get(0));
        for (int i = 1; i < n; i++) {
            sumList.add(sumList.get(i - 1) + priceList.get(i));
        }
        int m = scan.nextInt();
        for (int i = 0; i < m; i++) {
            int num = scan.nextInt();
            System.out.println(sumList.get(n - 1) - priceList.get(n - num));
        }
        scan.close();
    }
}