class Solution(object):
    def totalFruit(self, fruits):
        freq={}
        left=0
        max_fruits=0
        for right in range(len(fruits)):
            fruit=fruits[right]
            freq[fruit]=freq.get(fruit,0)+1

            if len(freq)>2:
                left_fruit=fruits[left]
                freq[left_fruit] -= 1

                if freq[left_fruit] == 0:
                    del freq[left_fruit]
                left+=1
            if len(freq)<=2:
                max_fruits=max(max_fruits,right-left+1)
        return max_fruits