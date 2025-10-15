import java.util.*;

public class BucketSort {
    public static void bucketSort(float[] arr) {
        int n = arr.length;
        if (n <= 0)
            return;

        @SuppressWarnings("unchecked")
        List<Float>[] buckets = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<>();
        }

        for (float value : arr) {
            int index = (int) (value * n);
            buckets[index].add(value);
        }

        for (List<Float> bucket : buckets) {
            Collections.sort(bucket);
        }

        int idx = 0;
        for (List<Float> bucket : buckets) {
            for (float value : bucket) {
                arr[idx++] = value;
            }
        }
    }

    public static void main(String[] args) {
        float[] arr = {0.42f, 0.32f, 0.23f, 0.52f, 0.25f, 0.47f, 0.51f};
        System.out.println("Before sorting: " + Arrays.toString(arr));
        bucketSort(arr);
        System.out.println("After sorting: " + Arrays.toString(arr));
    }
}
