def countFreq(arr, n):

	mp = dict()

	for i in range(n):
		if arr[i] in mp.keys():
			mp[arr[i]] += 1
		else:
			mp[arr[i]] = 1
			
    sorted(mp.items(), key=lambda item: item[1])
	

# Driver code
arr = [10, 20, 20, 10, 10, 20, 5, 20 ]
n = len(arr)
countFreq(arr, n)

