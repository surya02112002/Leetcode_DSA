class Solution:
    def countTriples(self, n):
        output = 0
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                target = a * a + b * b
                root = int(target ** 0.5)
                if root * root == target and root <= n:
                    output += 1
        return output
