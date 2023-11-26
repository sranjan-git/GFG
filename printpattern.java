class Solution {
    public static List<Integer> pattern(int N) {
        ArrayList<Integer> result = new ArrayList<>();
        generatePattern(N, result);
        return result;
    }

    private static void generatePattern(int N, ArrayList<Integer> result) {
        if (N <= 0) {
            result.add(N);
            return;
        }

        result.add(N);
        generatePattern(N - 5, result);

        if (N > 0) {
            result.add(N);
        }
    }
}
