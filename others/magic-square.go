package main

import (
	"fmt"
	"time"
)

func MakeMagicSquare(n int) [][]int {
	ret := make([][]int, n)
	for i := range ret {
		ret[i] = make([]int, n)
	}
	nn := n*n + 1
	var i, j int
	i = 0
	j = n / 2
	for c := 1; c < nn; c++ {
		ret[i][j] = c
		i = i - 1
		j = j + 1
		if i == -1 && j == n {
			i = 1
			j = n - 1
		} else {
			if i == -1 || j == n {
				if i == -1 {
					i = n - 1
				}
				if j == n {
					j = 0
				}
			} else if ret[i][j] > 0 {
				i = i + 2
				j = j - 1
			}
		}
	}

	return ret
}

func main() {
	a := time.Now()
	MakeMagicSquare(221)
	d := time.Since(a)
	fmt.Println(d)
}