import numpy as np
from scipy.sparse import csr_matrix

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        if n == 0: return []

        dtype = [('pos', 'i4'), ('health', 'i4'), ('dir', 'i4'), ('idx', 'i4')]
        data = np.empty(n, dtype=dtype)
        data['pos'] = positions
        data['health'] = healths
        data['dir'] = [1 if d == 'R' else -1 for d in directions]
        data['idx'] = np.arange(n)
        data.sort(order='pos')

        H = data['health'].astype(np.float64)
        V = data['dir']
        
     
        stack = []  
        alive = np.ones(n, dtype=bool)

        for i in range(n):
            if V[i] == 1:
                stack.append(i)
            else:
                
                while stack and H[i] > 0:
                    r_idx = stack[-1]
                    if H[r_idx] > H[i]:
                       
                        H[r_idx] -= 1
                        H[i] = 0
                        alive[i] = False
                        break
                    elif H[r_idx] < H[i]:
                        
                        H[r_idx] = 0
                        alive[r_idx] = False
                        stack.pop()
                        H[i] -= 1
                    else:
                       
                        H[r_idx] = 0
                        H[i] = 0
                        alive[r_idx] = False
                        alive[i] = False
                        stack.pop()
                        break

       
        survived_indices = data['idx'][alive]
        survived_healths = H[alive]
        
       
        order = np.argsort(survived_indices)
        return survived_healths[order].astype(int).tolist()