public class BinarySearch {
    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid; // Element found at index 'mid'
            } else if (arr[mid] < target) {
                left = mid + 1; // Search the right half of the array
            } else {
                right = mid - 1; // Search the left half of the array
            }
        }

        return -1; // Element not found in the array
    }
}