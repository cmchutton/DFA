#include<iostream>
using namespace std;

public class State {
			// private default access
		 	boolean finalState = false;
	 		boolean acceptState = false;
	 		char q;

	public:
		 	state(char q)
		 {
			 this.q = q;
		 }

	 		char getq() {
				return q;
			}

			void setq(char q) {
				this.q = q;
			}

			boolean isFinalState() {
				return finalState;
			}

			void setFinalState(boolean finalState) {
				this.finalState = finalState;
			}

			boolean isAcceptState() {
				return acceptState;
			}

			void setAcceptState(boolean acceptState)
			{
				this.acceptState = acceptState;
			}
};
