package main

import "fmt"

func main() {
	// a := [3]int{1, 2, 3}
	b := [...][2]int{{1, 2},{4,3}}
	fmt.Println(b)
	fmt.Println(len(b))
	fmt.Println(len(b[0]))
}
