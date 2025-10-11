// Quick Sort implementation in JavaScript

function quickSort(arr, left = 0, right = arr.length - 1) {
    if (left < right) {
        // Partition the array and get pivot index
        const pivotIndex = partition(arr, left, right);
        // Recursively sort left and right partitions
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
    return arr;
}

function partition(arr, left, right) {
    // Choose rightmost element as pivot
    const pivot = arr[right];
    let wall = left;
    // Move elements smaller than pivot to left side
    for (let i = left; i < right; i++) {
        if (arr[i] < pivot) {
            [arr[i], arr[wall]] = [arr[wall], arr[i]]; // swap
            wall++;
        }
    }
    // Place pivot at correct position
    [arr[wall], arr[right]] = [arr[right], arr[wall]];
    return wall; // return pivot index
}

// Example usage:
const arr = [6, 8, 1, 5, 9, 3, 2];
console.log("Before sorting:", arr);

quickSort(arr);

console.log("After sorting:", arr);
