+++
title = "leetcode-四数之和"
date = 2022-03-28T19:54:00+08:00
lastmod = 2022-03-28T20:39:05+08:00
tags = ["leetcode", "double-point"]
categories = ["leetcode"]
draft = false
toc = true
math = true
+++

## Problem Description {#problem-description}

{{< figure src="/ox-hugo/2022-02-16_14-14-26_screenshot.png" >}}


## Analyse {#analyse}

这题和3数之和的解法几乎一样，使用双指针枚举最后两个数字，所以我直接偷懒，拿了3数之和的代码稍微改了一下解决了这一题。


## Implement {#implement}

```go
func fourSum(nums []int, target int) [][]int {
    result := [][]int{}
    if len(nums) < 4 {
        return result
    }
    sort.Ints(nums)
    for i := 0; i < len(nums)-3; i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        ntarget := target - nums[i]
        tmp := threeSum(nums[i+1:], nums[i], ntarget)
        for _, value := range tmp {
            result = append(result, value)
        }
    }
    return result
}

func threeSum(nums []int, first int, target int) [][]int {
    result := [][]int{}
    if len(nums) < 3 {
        return result
    }

    for i := 0; i < len(nums); i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }

        k := len(nums) - 1
        ntarget := target - nums[i]

        for j := i + 1; j < len(nums); j++ {
            if j > i+1 && nums[j] == nums[j-1] {
                continue
            }

            for j < k && nums[j]+nums[k] > ntarget {
                k--
            }

            if j == k {
                break
            }

            if nums[j]+nums[k] == ntarget {
                result = append(result, []int{first, nums[i], nums[j], nums[k]})
            }
        }
    }
    return result
}
```


## Summery {#summery}
