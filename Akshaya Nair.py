
m, x = [0] * 1000, [0] * 22

a = [[0 for i in range(22)]
		for j in range(1000)]
ans = 0

def dfs(u, p):

	global ans
	for i in range(0, len(g[u])):
		v = g[u][i]
		if v != p:
			dfs(v, u)

			for i in range(0, 22):
				a[u][i] += a[v][i]

	pp = 0
	for i in range(0, 22):
		if (not((a[u][i] > 0 and
				x[i] - a[u][i] > 0)
			or (a[u][i] == 0 and x[i] == 0))):
			pp = 1
			break
		
	if pp == 0:
		ans += 1

# Driver code
def getNumWays(g_nodes, g_from, g_to, values):

	# Number of nodes
	n = g_nodes[0]

	# ArrayList to store the tree
	g = [[] for i in range(n+1)]

	m[1] = 1
	m[2] = 3
	m[3] = 2
	m[4] = 3

	for i in range(1, n+1):
		y, k = m[i], 0

		while y != 0:
			p = y % 2
			if p == 1:
				x[k] += 1
				a[i][k] += 1
			
			y = y // 2
			k += 1
		for i in range(0, g_nodes[1]):
            g.[g_from[i]].append(g_to[i])
            
	dfs(1, 0)
	return ans

# This code is contributed by Rituraj Jain
