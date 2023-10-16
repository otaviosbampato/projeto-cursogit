#include <iostream>


class noh{
    friend class fila;
    private:
        noh* mInicio;
        noh* mFim;
        int mTamanho;
    public:
        noh();
        ~noh();
};

noh::noh(){
    mInicio = NULL;
    mFim = NULL;
    int mTamanho = 0;
}

class fila{
    private:
        


};

int main(){

    int num;
    std::cout << "\n\ninsira um numero:";

    std::cin >> num;

    std::cout << "o quadrado do seu numero é:";
    std::cout << num*num << "\n\n";

    return 0;
}