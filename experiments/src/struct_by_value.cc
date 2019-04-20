#include <iostream>

struct MyMatrix {
    int _dummy;
    float reserved[4];

    int width;
    int height;
    float* elements;
};

//MyMatrix&& make_matrix(int w, int h) {
MyMatrix make_matrix(int w, int h) {
    MyMatrix input;

    input.width = w;
    input.height = h;
    input.elements = new float[w*h];

    // return std::move(input);
    return input;
}

void free_matrix(MyMatrix& input) {
    delete[] input.elements;
    input.elements = nullptr;
}

/**
 * This function takes a struct (MyMatrx) by _value_, not reference/pointer.
 * It seems strange at first, but this function still works.The caller will
 * still see the value of its MyMatrix.elements[r][c] change. Why is this?
 * Perhaps a better question is why _wouldn't_ it work? The answer there is
 * that taking a struct by copy seems like it would only make the change to the
 * copied version. This intuition is correct in that when set_element(<matrix>)
 * is called, <matrix> will be copied and passed to the function. However,
 * just because it's a copy, doesn't mean it can't change the elements array.
 * That is because the elements array is a pointer. And a pointer is just an
 * address--a value. A pointer is just a 32/64 bit int. It points to a location
 * in memory. If you copy a raw pointer, you just get another int with
 * the value of the address. And that address is still valid in the case
 * of MyMatrix.elements because it was dynamically allocated.
 */
void set_element(MyMatrix a, int r, int c, float value) {
    int idx_1d = a.width*r + c;

    if (idx_1d < a.width*a.height - 1) {
        a.elements[idx_1d] = value;
    } else {
        std::cerr << "Tried to set out-of-bounds\n";
    }
}

float get_element(const MyMatrix& a, int r, int c) {
    int idx_1d = a.width*r + c;

    if (idx_1d < a.width*a.height - 1) {
        return a.elements[idx_1d];
    } else {
        std::cerr << "Tried to get out-of-bounds\n";
        return 0;
    }
}

/**
 * Setting a MyMatrix.reserved element when passing MyMatrix by value does
 * not affect the original version. This is because the reserved array
 * is just a chunk of 4 floats in the struct, not a pointer. The values of
 * the original reserved array are copied, changed, and then destroyed.
 */
void set_reserved(MyMatrix a, int i, float value) {
    if (i < 4) {
        a.reserved[i] = value;
    } else {
        std::cerr << "Tried to set out-of-bounds\n";
    }
}

float get_reserved(const MyMatrix& a, int i) {
    if (i < 4) {
        return a.reserved[i];
    } else {
        std::cerr << "Tried to get out-of-bounds\n";
        return 0;
    }
}

/**
 * Same case as with reserved array. In both cases, the copy is changing
 * its own version.
 */
void set_dummy_copy(MyMatrix a, int value) {
    a._dummy = value;
}

/**
 * Passing the struct by reference allows us to modify the orignal
 */
void set_dummy_ref(MyMatrix& a, int value) {
    a._dummy = value;
}

int get_dummy(const MyMatrix& a) {
    return a._dummy;
}

int main() {
    auto a = make_matrix(5, 5);

    set_element(a, 0, 0, 3.14);
    std::cout << "a.elements[0][0] = " << get_element(a, 0, 0) << '\n';

    set_reserved(a, 1, 17);
    std::cout << "a.reserved[1] = " << get_reserved(a, 1) << '\n';

    set_dummy_copy(a, 4);
    std::cout << "a._dummy = " << get_dummy(a) << '\n';

    set_dummy_ref(a, 4);
    std::cout << "a._dummy = " << get_dummy(a) << '\n';

    free_matrix(a);
}
