def main():
    array = [1,2,4,5,32,2,34,23,20]
    def bubble_sort():
        print(array)
        # Bubble sort algorithm
        n = len(array)
        for i in range(n-1):
            for j in range(n-i-1):
                if array[j] > array[j+1]:
                    array[j], array[j+1] = array[j+1], array[j]
        print(array)   

    def optemized_bubble_sort():
        print(array)
        # Bubble sort algorithm
        n = len(array)
        for i in range(n-1):
            swapped = False
            for j in range(n-i-1):
                if array[j] > array[j+1]:
                    array[j], array[j+1] = array[j+1], array[j]
                    swapped = True
            if not swapped:
                break        
        print(array)
    optemized_bubble_sort()    
     

main()