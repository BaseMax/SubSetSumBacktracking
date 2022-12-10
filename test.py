import subsetsum

target = 0
nums = [-2, -1, 0, 1, 2]

has_solution = subsetsum.has_solution(nums, target)
print(f"Can {nums} sum to {target}? {has_solution}")

for solution in subsetsum.solutions(nums, target):
    # `solution` contains indices of elements in `nums`
    subset = [nums[i] for i in solution]
    sum_value = sum(subset)
    print(f"{subset} sums to {sum_value}")
