public final class GCDRecursion {
    private GCDRecursion() {
    }

    public static void main(String[] args) {
        System.out.println(gcd(20, 15));
        System.out.println(gcd(10, 8));
        System.out.println(gcd(gcd(10, 5), gcd(5, 10)));
    }

    public static int gcd(int a, int b) {
        if (a < 0 || b < 0) {
            throw new ArithmeticException();
        }

        if (a == 0 || b == 0) {
            return Math.abs(a - b);
        }

        if (a % b == 0) {
            return b;
        } else {
            return gcd(b, a % b);
        }
    }
}