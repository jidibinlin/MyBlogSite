package main

func main() {
//go version
import "math"
func maxArea(height []int) int {
    front := 0
    end := len(height)-1

    var maxCompacity float64 = 0

    for front < end {
        longSide := math.Min(float64(height[front]),float64(height[end]))
        shotSide := float64(end-front)
        tmpCompacity := longSide*shotSide
        maxCompacity = math.Max(tmpCompacity,maxCompacity)
        if height[front] >= height[end] {
            end--
        }else{
            front++
        }
    }
    return int(maxCompacity)
}
}
