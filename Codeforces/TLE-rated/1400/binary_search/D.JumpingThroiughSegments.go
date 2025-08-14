package main

import (
    "bufio"
    "fmt"
    "os"
)
func min(a, b int) int {
    if a > b {
        return b
    }
    return a
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func is_possible(m int, arr [][]int) bool {
    if m < arr[0][0] {
        return false
    }
    mi := arr[0][0]
    ma := min(arr[0][1], m)
    for i := 1; i < len(arr); i++ {
        mi = mi-m;
        ma = ma+m;
        if arr[i][1] < mi || arr[i][0] > ma {
         return false;
        }
        mi= max(mi,arr[i][0])
        ma=min(ma,arr[i][1])
    }
  //  fmt.Println()
    return true
}

func main() {
    in := bufio.NewReader(os.Stdin)
    var t int
    fmt.Fscan(in, &t)
    for tc := 0; tc < t; tc++ {
        var n int
        fmt.Fscan(in, &n)
        arr := make([][]int, n)
        var r int
        for i := 0; i < n; i++ {
            arr[i] = make([]int, 2)
            for j := 0; j < 2; j++ {
                fmt.Fscan(in, &arr[i][j])
                r = max(r, arr[i][j])
            }
        }

        l := 0
        ans := r
        for l <= r {
            m := l + (r-l)/2
           // fmt.Println(m)
            if is_possible(m, arr) {
                ans = m
                r = m - 1
            } else {
                l = m + 1
            }
        }
        fmt.Println(ans)
    }
}
