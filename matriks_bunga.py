

def flower(M,k,l):

    row, col =  len(M),len(M[0])
    k_row,l_col = row*k, col*l

    # Membuat matriks baru R berukuran km*kn
    result = []
    for i in range(k_row):
        result.append([None]*l_col)

    for i in range(row):
        for j in range(col):
            # Memekarkan setiap matrik i,j ke i+k dan j+k
            for x in range(i*k , (i+1)*k ):
                for y in range(j*l , (j+1)*l):
                    result[x][y] = M[i][j]
    
    return result


if __name__ == "__main__":
    
    A = [[1,2],[3,4]]
    B = [['a','b','c'],['d','e','f'],['g','h','i']]
    print("A\n")
    for x  in flower(A,2,3):
        print(x)

    print("\nB\n")
    for x  in flower(B,3,3):
        print(x)
    