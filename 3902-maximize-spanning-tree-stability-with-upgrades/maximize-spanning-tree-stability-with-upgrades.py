class DSU:
    def __init__(self, n: int):
        self._parent = list(range(n))
    
    def _root(self, node: int) -> int:
        while self._parent[node] != node:
            self._parent[node] = self._parent[self._parent[node]]
            node = self._parent[node]
        return node
    
    def union(self, n1: int, n2: int) -> bool:
        r1, r2 = self._root(n1), self._root(n2)
        if r1 == r2:
            return False  # n1 and n2 are already connected
        elif r1 < r2:
            r1, r2 = r2, r1
        self._parent[r1] = r2
        return True

class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        tree = DSU(n)      # current spanning tree
        heap = []          # edges that are not required
        rem_edges = n - 1  # spanning tree must have exactly n - 1 edges
        res = inf          # minimum strength (stability)

        # process edges that must be in the spanning tree
        for a, b, strength, must in edges:
            if not must:
                heappush(heap, (-strength, a, b))
                continue
            elif not tree.union(a, b):
                return -1  # spanning tree already contains a cycle
            rem_edges -= 1
            res = min(res, strength)
        
        # find remaining edges with best strengths
        while rem_edges:
            if not heap:
                return -1  # no more edges to finish spanning tree
            strength, a, b = heappop(heap)
            if not tree.union(a, b):
                continue  # including this edge will form a cycle
            # greedily apply upgrades to weakest k
            res = min(res, -strength * 2 ** (rem_edges <= k))
            rem_edges -= 1

        return res