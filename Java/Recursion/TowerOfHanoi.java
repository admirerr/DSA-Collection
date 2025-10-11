// This function will give you step by step method to solve the tower of hanoi for n disks
public class TowerOfHanoi {     //time complexity = O(2**n)
    public static void towerOfHanoi(int n, String source, String helper, String dest){
        //taking function arguments: n = number of disks, source, helper and destination
        if(n == 1){ //Base case: when there is only one disk we will simply transfer ir from source to destination
            System.out.println("Transfer disk " + n + " from " + source + " to " + dest);
            return;
        }
        towerOfHanoi(n-1, source, dest, helper); //we will use recursive call for remaining n-1 disks by using destination as helper and helper as destination
        System.out.println("Transfer disk " + n + " from " + source + " to " + dest);
        towerOfHanoi(n-1, helper , source , dest); //again making recursive call now taking source as helper and helper as source
    }

    public static void main(String[] args) {
        towerOfHanoi(3, "A", "B", "C");
    }
}
//you can understand this more clearly by using visual solving for n=3