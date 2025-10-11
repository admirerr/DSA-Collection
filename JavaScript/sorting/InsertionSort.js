// Insertion Sort implementation in JavaScript

function insertionSort(arr) {
    // Iterate from the second element to the end
    for (let i = 1; i < arr.length; i++) {
        let key = arr[i];
        let j = i - 1;
        // Shift elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Place key at after the element just smaller than it
        arr[j + 1] = key;
    }
    return arr;
}

// Example usage:
const arr = [8, 2, 4, 1, 3];
console.log("Before sorting:", arr);

insertionSort(arr);

console.log("After sorting:", arr);
