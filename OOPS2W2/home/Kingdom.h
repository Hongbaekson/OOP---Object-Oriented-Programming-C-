/***********************************************************
//HongbackSon(133181164, hbson1@myseneca.ca)

***********************************************************/

// TODO: header safeguards

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace

namespace sict {
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	// TODO: declare the function display(...),
	//         also in the sict namespace

	void display(const struct Kingdom &kingdom );
	void display(const struct Kingdom *kingdom, int numberOfRec);
}

#endif




