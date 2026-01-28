class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        available  = [sorted([(grid[i][j], i, j) for i in range(len(grid)) for j in range(len(grid[0]))], reverse = True) for K in range(k)]
        heap = [(0, 0, 0, 0)] # cost, x, y, teleports
        vis = [[11 for i in range(len(grid[0]))] for j in range(len(grid))] # 11 cause max teleports is 10
        while heap:
            cost, x, y, tps = heapq.heappop(heap)
            if x == len(grid) - 1 and y == len(grid[0]) - 1:
                return cost
            if vis[x][y] <= tps:
                continue
            vis[x][y] = tps
            if x + 1 < len(grid):
                heapq.heappush(heap, (cost + grid[x + 1][y], x + 1, y, tps))
            if y + 1 < len(grid[0]):
                heapq.heappush(heap, (cost + grid[x][y + 1], x, y + 1, tps))
            while tps < k and available[tps] and available[tps][-1][0] <= grid[x][y]:
                c1, x1, y1 = available[tps].pop()
                heapq.heappush(heap, (cost, x1, y1, tps + 1))