import java.math.BigInteger;
import java.util.Random;

public final class EulerPseudoprime {

    private EulerPseudoprime() {}

    private static final Random RANDOM = new Random();

    public static boolean isProbablePrime(BigInteger n, int trials) {
        if (n.compareTo(BigInteger.TWO) < 0) {
            return false;
        }
        if (n.equals(BigInteger.TWO) || n.equals(BigInteger.valueOf(3))) {
            return true;
        }
        if (n.mod(BigInteger.TWO).equals(BigInteger.ZERO)) {
            return false;
        }

        for (int i = 0; i < trials; i++) {
            BigInteger a = uniformRandom(BigInteger.TWO, n.subtract(BigInteger.TWO));
            BigInteger jacobi = BigInteger.valueOf(jacobiSymbol(a, n));

            if (jacobi.equals(BigInteger.ZERO)) {
                return false;
            }

            BigInteger exp = n.subtract(BigInteger.ONE).divide(BigInteger.TWO);
            BigInteger modExp = a.modPow(exp, n);

            if (!modExp.equals(jacobi.mod(n))) {
                return false;
            }
        }
        return true;
    }

    public static int jacobiSymbol(BigInteger a, BigInteger n) {
        if (n.signum() <= 0 || n.mod(BigInteger.TWO).equals(BigInteger.ZERO)) {
            throw new IllegalArgumentException("n must be a positive odd integer.");
        }

        int result = 1;
        a = a.mod(n);

        while (a.compareTo(BigInteger.ZERO) != 0) {
            while (a.mod(BigInteger.TWO).equals(BigInteger.ZERO)) {
                a = a.divide(BigInteger.TWO);
                BigInteger nMod8 = n.mod(BigInteger.valueOf(8));
                if (nMod8.equals(BigInteger.valueOf(3)) || nMod8.equals(BigInteger.valueOf(5))) {
                    result = -result;
                }
            }

            BigInteger temp = a;
            a = n;
            n = temp;

            if (a.mod(BigInteger.valueOf(4)).equals(BigInteger.valueOf(3)) && n.mod(BigInteger.valueOf(4)).equals(BigInteger.valueOf(3))) {
                result = -result;
            }
            a = a.mod(n);
        }
        return n.equals(BigInteger.ONE) ? result : 0;
    }

    private static BigInteger uniformRandom(BigInteger min, BigInteger max) {
        BigInteger result;
        do {
            result = new BigInteger(max.bitLength(), RANDOM);
        } while (result.compareTo(min) < 0 || result.compareTo(max) > 0);
        return result;
    }

    public static void main(String[] args) {
        // Define the numbers to test and the number of trials for the test.
        int trials = 20;
        String[] testNumbers = {
            "7",       // Small prime
            "10",      // Small even composite
            "91",      // Small odd composite
            "563",     // A known prime number
            "1105",    // An Euler pseudoprime to base 2
            "294409",  // A larger prime number
            "294411"   // A larger composite number
        };

        System.out.printf("Running Euler Primality Test with %d trials...%n%n", trials);

        for (String numStr : testNumbers) {
            BigInteger n = new BigInteger(numStr);
            boolean isPrime = isProbablePrime(n, trials);
            String result = isPrime ? "Probably Prime" : "Composite";
            System.out.printf("Is %s prime? --> %s%n", n, result);
        }
    }
}