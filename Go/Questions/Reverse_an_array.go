package main

import (
	"fmt"
	// "math"
	// "sort"
)

// Method 1

// func reverseArray(n int, arr []int) []int {
// 	var temp int
// 	for i := 0; i < int(math.Ceil(float64(n/2))); i++ {
// 		temp = arr[i]
// 		arr[i] = arr[n-1-i]
// 		arr[n-1-i] = temp
// 	}
// 	return arr
// }

// func main() {
// 	var a = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
// 	fmt.Println(a)
// 	c := reverseArray(len(a), a)
// 	for i := 0; i < len(c); i++ {
// 		fmt.Printf("%d ", c[i])
// 	}
// 	fmt.Println()
// 	var b = []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
// 	fmt.Println(b)
// 	d := reverseArray(len(b), b)
// 	for i := 0; i < len(d); i++ {
// 		fmt.Printf("%d ", d[i])
// 	}
// 	fmt.Println()
// }

// Method 2

// func reverseArray(n int, arr []int) []int {
// 	for i := 0; i < int(math.Ceil(float64(n/2))); i++ {
// 		arr[i], arr[n-1-i] = arr[n-1-i], arr[i]

// 	}
// 	return arr
// }

// func main() {
// 	var a = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
// 	fmt.Println(a)
// 	c := reverseArray(len(a), a)
// 	for i := 0; i < len(c); i++ {
// 		fmt.Printf("%d ", c[i])
// 	}
// 	fmt.Println()
// 	var b = []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
// 	fmt.Println(b)
// 	d := reverseArray(len(b), b)
// 	for i := 0; i < len(d); i++ {
// 		fmt.Printf("%d ", d[i])
// 	}
// 	fmt.Println()
// }

// Method 3

// Works but sorts the initial list
// func main() {
// 	var a = []int{1, 2, 341, 44532, 543, 67, 658, 768657, 978, 9, 87, 9, 6, 5, 667, 4356, 23, 45, 235, 4, 125, 243, 654, 36, 7}
// 	fmt.Println(a)
// 	sort.Sort(sort.Reverse(sort.IntSlice(a)))
// 	fmt.Println(a)
// 	var b = []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
// 	fmt.Println(b)
// 	sort.Sort(sort.Reverse(sort.IntSlice(b)))
// 	fmt.Println(b)
// }

// Method 4

// DOES NOT WORK
// func main() {
// 	var a = []int{1, 2, 341, 44532, 543, 67, 658, 768657, 978, 9, 87, 9, 6, 5, 667, 4356, 23, 45, 235, 4, 125, 243, 654, 36, 7}
// 	fmt.Println(a)
// 	c := sort.Reverse(sort.IntSlice(a))
// 	fmt.Println(c)
// 	var b = []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
// 	fmt.Println(b)
// 	d := sort.Reverse(sort.IntSlice(b))
// 	fmt.Println(d)
// }

// Method 5 (Removing redundant logic from method 2)

func reverseArray(n int, arr []int) []int {
	for i := 0; i < n/2; i++ {
		arr[i], arr[n-1-i] = arr[n-1-i], arr[i]

	}
	return arr
}

// func main() {
// 	var a = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
// 	fmt.Println(a)
// 	c := reverseArray(len(a), a)
// 	for i := 0; i < len(c); i++ {
// 		fmt.Printf("%d ", c[i])
// 	}
// 	fmt.Println()
// 	var b = []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
// 	fmt.Println(b)
// 	d := reverseArray(len(b), b)
// 	for i := 0; i < len(d); i++ {
// 		fmt.Printf("%d ", d[i])
// 	}
// 	fmt.Println()
// }

// Taking array as input
func main() {
	var size int
	fmt.Scanln(&size)
	var arr = make([]int, size)
	for i := 0; i < size; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	for i := 0; i < size; i++ {
		fmt.Printf("%d ", arr[i])
	}
	fmt.Println()
	fmt.Println(arr)
	d := reverseArray(len(arr), arr)
	for i := 0; i < len(d); i++ {
		fmt.Printf("%d ", d[i])
	}
	fmt.Println()
	fmt.Println(d)
}
