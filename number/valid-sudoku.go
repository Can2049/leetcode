// https://leetcode.com/problems/valid-sudoku/

package main

import "fmt"

func isValidSudoku(board [][]byte) bool {
	// for rows
	for r := 0; r < 9; r++ {
		// var xor1 byte = 0 // rows
		// var xor2 byte = 0 // columns
		ar := [10]bool{}
		ac := [10]bool{}
		for c := 0; c < 9; c++ {
			var char1 byte = board[r][c] - '0'
			if char1 <= 9 && char1 >= 1 {
				if ar[char1] == false {
					ar[char1] = true
				} else {
					return false
				}
			}
			var char2 byte = board[c][r] - '0'
			if char2 <= 9 && char2 >= 1 {
				if ac[char2] == false {
					ac[char2] = true
				} else {
					return false
				}
			}
		}

	}
	for r := 0; r < 3; r++ {
		for c := 0; c < 3; c++ {
			// var xor byte = 0
			a := [10]bool{}
			for i := 0; i < 3; i++ {
				for j := 0; j < 3; j++ {
					char := board[r*3+i][c*3+j] - '0'
					if char <= 9 && char >= 1 {
						if a[char] == false {
							a[char] = true
						} else {
							return false
						}
					}
				}
			}
		}
	}
	return true
}

func main() {
	fmt.Println("kkk")
}
