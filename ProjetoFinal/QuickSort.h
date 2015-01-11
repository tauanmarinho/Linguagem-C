#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
// Função de Ordenação por Seleção
// Selection sort function
//OrdenaQuickSort(vet, 0, MAX - 1);

void OrdenaQuickSort(int *VetTemp, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = VetTemp[(left + right) / 2];

    while(i <= j)
    {
        while(VetTemp[i] < x && i < right)
        {
            i++;
        }
        while(VetTemp[j] > x && j > left)
        {
            j--;
        }
        if(i <= j)
        {
            y = VetTemp[i];
            VetTemp[i] = VetTemp[j];
            VetTemp[j] = y;
            i++;
            j--;
        }
    }

    if(j > left)
    {
        OrdenaQuickSort(VetTemp, left, j);
    }
    if(i < right)
    {
        OrdenaQuickSort(VetTemp, i, right);
    }
}


#endif // QUICKSORT_H_INCLUDED
