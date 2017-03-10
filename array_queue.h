#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {

template<typename T>
class ArrayQueue {
public:
    //! Construtor
    /*!
        Cria um array com o tamanho de DEFAULT_SIZE e inicializa size_ com -1
    */
    ArrayQueue();

    //! Construtor que cria array com tamanho do parametro
    /*!
        \param max tipo size_t demarca o tamanho do array criado
        Cria um array com o tamanho do parametro e inicializa size_ com -1
    */
    ArrayQueue(std::size_t max);

    //! Destrutor
    ~ArrayQueue();

    //! Funçao coloca na fila
    /*!
        \param data elemento a ser inserido na fila
        \return void
        Se fila estiver cheia retorna excessão, senão adiciona elemento na fila
        e incrementa _size
    */
    void enqueue(const T& data);

    //! Funçao retira da fila
    /*!
        \return T
        Se fila estiver vazia retorna excessão, senão retorna primeiro
        elemento que entrou na fila, decrementa _size
    */
    T dequeue();

    //! Funçao back
    /*!
        \return &T
        retorna primeiro elemento que entrou na fila
    */
    T& back();

     //! Funçao limpa fila
    /*!
        \return void
        atribui -1 à size_
    */
    void clear();

    //! Funçao size
    /*!
        \return size_t
        retorna tamanho da fila
    */
    std::size_t size();

    //! Funçao max_size
    /*!
        \return size_t
        retorna tamanho maximo possivel da fila
    */
    std::size_t max_size();

    //! Funçao vazio
    /*!
        \return bool
        retorna true se fila estiver vazia
    */
    bool empty();

    //! Funçao cheia
    /*!
        \return bool
        retorna true se fila estiver cheia
    */
    bool full();

private:
    //! Ponteiro T
    /*!
        Aponta para a fila
    */
    T* contents;
    
    //! Uma variável size_t
    /*!
        Indica o tamanho da fila
    */
    std::size_t size_;
    
    //! Uma variável size_t
    /*!
        Indica o máximo tamanho possível da fila
    */
    std::size_t max_size_;

    //! Uma variável size_t
    /*!
        Indica o tamanho default da fila
    */
    const static auto DEFAULT_SIZE = 10u;
};

template <class T>
ArrayQueue<T>::ArrayQueue() {
    size_ = -1;
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
}

template <class T>
ArrayQueue<T>::ArrayQueue(std::size_t max) {
    size_ = -1;
    max_size_ = max;
    contents = new T[max_size_];
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
    delete contents;
}

template <class T>
bool ArrayQueue<T>::empty() {
    return (size_ == -1);
}

template <class T>
bool ArrayQueue<T>::full() {
    return (size_ + 1 == max_size_);
}

template <class T>
std::size_t ArrayQueue<T>::size() {
    return (size_ + 1);    
}

template <class T>
std::size_t ArrayQueue<T>::max_size() {
    return max_size_;    
}

template <class T>
void ArrayQueue<T>::clear() {
    size_ = -1;    
}

template <class T>
T& ArrayQueue<T>::back() {
    if (empty()) {
        throw std::out_of_range ("Empty Queue");
    }
    else {
        return contents[size_];
    }
}

template <class T>
T ArrayQueue<T>::dequeue () {
    if (empty()) {
        throw std::out_of_range ("Empty Queue");
    }
    else {
        T temp = contents[0];
        for (std::size_t i = 0; i < size_; ++i) {
            std::cout << i << std::endl;
            contents[i] = contents[i + 1];
            std::cout << i << std::endl;
        }
        --size_;
        return temp;
    }
}

template <class T>
void ArrayQueue<T>::enqueue (const T& data) {
    if (full()) {
        throw std::out_of_range("Full Stack");
    }
    else {
        ++size_;
        contents[size_] = data;
    }
}

}

#endif
