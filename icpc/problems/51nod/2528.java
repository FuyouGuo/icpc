import java.util.*;

// 在51nod上提交需要在类前加public
class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        List<Integer> v = new ArrayList<Integer>(n);
        for(int i = 0; i < n; i++){
            v.add(scan.nextInt());
        }
        scan.close();
        Collections.sort(v);
        if (n == 2) {
            System.out.println(v.get(1) - v.get(0));
        } else {
            int val = Integer.MIN_VALUE;
            for(int i = 2; i < n; i++){
                val = Math.max(val, v.get(i) - v.get(i-2));
            }
            System.out.println(val);
        }
    }
}