
def tri_selection(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def main():
    # Lecture de references.txt
    with open('C:/Users/julie/OneDrive/Documents/Hutech/GI04 P24/IS05/Experimentations_wsl/references.txt', 'r', encoding='UTF-8') as file:
        references = [int(line.strip()) for line in file]

    tri_selection(references)

    # Écriture du fichier trié references-tri-selection.txt
    with open('C:/Users/julie/OneDrive/Documents/Hutech/GI04 P24/IS05/Experimentations_wsl/references-tri-selection.txt', 'w') as file:
        for reference in references:
            file.write(str(reference) + '\n')
    
    print("Le fichier trié a été créé avec succès.")

if __name__ == "__main__":
    main()

