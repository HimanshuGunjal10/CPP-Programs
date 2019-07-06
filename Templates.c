---------------------------------------
Templates:
Use generic type of data instead of specific type of data like a placeholder

	template <class BUCKY>

	int add( int a, int b) /*turns into*/ BUCKY add (BUCKY a, BUCKY b) {...} 		// keep it in CAPS

to mix n match int and double etc, template <class FIRST, class SECOND>

	FIRST add(FIRST a, SECOND b) {...} 		//FIRST and SECOND are known as generic classes

--
Template classes : 3 additions needed

#1		template <class T>
		class Bucky
			{
				T first, second;
			public:
				Bucky (T a, T b) : first(a), second(b) {}
				T bigger();
			};

#2		template <class T>
		T bucky<T>::bigger ()
		{
			return (first>second?first:second);
		}

		int main()
		{
#3			Bucky <int> bo(10,11);		//<int> in between the class and object name
			bo.bigger();
		}

--

Template Specialization:
When you want your template to accept all types of data but if it gets one specific data it should behave in a special way.

