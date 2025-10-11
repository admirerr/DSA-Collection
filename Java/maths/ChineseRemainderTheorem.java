
import java.util.List;
import java.util.Arrays;

public class ChineseRemainderTheorem {

    private ChineseRemainderTheorem() {
    }

    public static int solveCRT(List<Integer> remainders, List<Integer> moduli) {
        int product = 1;
        int result = 0;

        for (int mod : moduli) {
            product *= mod;
        }

        for (int i = 0; i < moduli.size(); i++) {
            int partialProduct = product / moduli.get(i);
            int inverse = modInverse(partialProduct, moduli.get(i));
            result += remainders.get(i) * partialProduct * inverse;
        }

        result = result % product;
        if (result < 0) {
            result += product;
        }

        return result;
    }

    private static int modInverse(int a, int m) {
        int m0 = m;
        int x0 = 0;
        int x1 = 1;

        if (m == 1) {
            return 0;
        }

        while (a > 1) {
            int q = a / m;
            int t = m;

            m = a % m;
            a = t;
            t = x0;

            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) {
            x1 += m0;
        }

        return x1;
    }

    public static void main(String[] args) {
        List<Integer> remainders = Arrays.asList(2, 3, 2);
        List<Integer> moduli = Arrays.asList(3, 5, 7);

        int solution = solveCRT(remainders, moduli);
        System.out.println("CRT Solution: " + solution);
    }
}

