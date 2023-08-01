public class UnboundedKnapsack {
    public static int unboundedKnapsack(int[] weights, int[] values, int capacity) {
        int[] dp = new int[capacity + 1];

        for (int i = 0; i <= capacity; i++) {
            for (int j = 0; j < weights.length; j++) {
                if (weights[j] <= i) {
                    dp[i] = Math.max(dp[i], dp[i - weights[j]] + values[j]);
                }
            }
        }

        return dp[capacity];
    }

    public static void main(String[] args) {
        int[] weights = { 2, 3, 4, 5 };
        int[] values = { 3, 4, 5, 6 };
        int capacity = 5;

        int maxValue = unboundedKnapsack(weights, values, capacity);
        System.out.println("Maximum value (Unbounded Knapsack): " + maxValue); // Output: 12
    }
}
