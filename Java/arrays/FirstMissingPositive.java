import java.util.Scanner;

class FirstMissingPositive {
    public static int firstMissingPositive(int[] nums) {
        for(int i = 0;i<nums.length;i++){
            if(nums[i]<=0||nums[i]>nums.length){
                nums[i] = 0;
            }
        }

        int i = 0;
        while(i<nums.length){
            if(nums[i]==0){
                i++;
            }else if(nums[i]!=nums[nums[i]-1]){
                swap(nums,i,nums[i]-1);
            }else{
                i++;
            }
        }

        int ans = nums.length+1;
        for(int j = 0;j<nums.length;j++){
            if(nums[j]!=j+1){
                ans = j+1;
                break;
            }
        }

        return ans;
    }

    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter the elements:");
        for(int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int missing = firstMissingPositive(nums);
        System.out.println("First missing positive: " + missing);
        sc.close();
    }
}
