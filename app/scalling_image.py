
from PIL import Image
import numpy as np

def flower(M,k,l):

    row, col =  len(M),len(M[0])
    k_row,l_col = row*k, col*l

    result = []
    for i in range(k_row):
        result.append([None]*l_col)

    for i in range(row):
        for j in range(col):
            for x in range(i*k , (i+1)*k ):
                for y in range(j*l , (j+1)*l):
                    result[x][y] = M[i][j]
    
    return result


def scale(M,k,l):

    row, col = M.size
    k_row,l_col = int(row*k), int(col*l)

    dim = len(M.mode)

    pixels = M.load()
    data = np.zeros((l_col,k_row,dim), dtype=np.uint8 )

    for i in range(col):
        for j in range(row):

            for x in range(int(i*l ), int((i+1)*l) ):
                for y in range(int(j*k) , int((j+1)*k)):
                    data[x,y] = pixels[j,i]
    
    image = Image.fromarray(data)
    image.save("out_"+M.filename)
    print("Successed")

if __name__ == "__main__":
    

    img = Image.open('test.png')
    scale(img,2,2)
    