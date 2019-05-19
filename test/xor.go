package main

import "fmt"

func main() {
	a := []int{2, 3, 4, 5, 0, 2}
	var ans = 0
	for _, value := range a {
		ans ^= value
	}

	fmt.Println(ans)
}
