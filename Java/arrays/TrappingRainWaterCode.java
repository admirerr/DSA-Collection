public class TrappingRainWaterCode {
    public static int trappedRainWater(int height[]) {
        // auxilliary array
        // calculate left max boundary array
        int[] leftMaxBound = new int[height.length];
        leftMaxBound[0] = height[0];
        for (int i = 1; i < height.length; i++) {
            leftMaxBound[i] = Math.max(height[i], leftMaxBound[i - 1]);// i starts with 1 since we have already
                                                                       // calculated 0.compares current height with prev
                                                                       // leftmax boundary

        }

        // calculate right max boundary
        int[] rightMaxBound = new int[height.length];
        rightMaxBound[height.length - 1] = height[height.length - 1];// for last element rightmax boundary will be
                                                                     // itself
        for (int i = height.length - 2; i >= 0; i--) {
            rightMaxBound[i] = Math.max(height[i], rightMaxBound[i + 1]);

        }
        int trappedWater = 0;
        // loop

        for (int i = 1; i < height.length; i++) {
            // water level->mix(left max boundary,right max boundary)
            int waterLevel = Math.min(leftMaxBound[i], rightMaxBound[i]);

            // trapped water->waterlevel-height[i]
            trappedWater += waterLevel - height[i];
        }
        return trappedWater;

    }

    public static void main(String[] args) {
        int[] height = { 4, 2, 0, 6, 3, 2, 5 };
        System.out.println(trappedRainWater(height));

    }
}
/* time complexity->is proportional to number of bars */