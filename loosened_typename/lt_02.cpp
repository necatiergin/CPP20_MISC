template <typename T>
struct PointerTrait {
	using Ptr = void*;
};

template<typename T>
struct Nec {
	using Ptr = PointerTrait<T>::Ptr;

	T::Neco foo(T::Ali x)
	{
		return static_cast<T::Neco>(x); //C++20. Valid
	}
};
