/**
 * mindcpp runtime
 *
 * Copyright (C) 2014 Schneider-Electric
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 * Contact: mind@ow2.org
 *
 * Authors: Julien Tous
 */

#ifndef MINDCPP_IDL_INTERFACEREFERENCE_HPP_
#define MINDCPP_IDL_INTERFACEREFERENCE_HPP_
#include "InterfaceDescriptor.hpp"

namespace Mind {

/**
 * \brief C++ Interface reference abstract class
 *
 * This class is extended by each C++ interface reference class generated by Mind tools according to your ITF description.
 */
template <typename AnInterfaceDescriptor>
class InterfaceReference {

// // FIXME check for protected, according to NMF's CPP.HPP InterfaceReference constructor.
public:
	/**
	 * \brief Target reference
	 *
	 * \warning This method is used internally, you must not use it.
	 */
	AnInterfaceDescriptor* reference;

public:
	inline InterfaceReference(){
		reference = 0; // FIXME check with NMF's CPP.HPP InterfaceReference constructor.
	};

	/**
	 * \brief Test if an interface reference is really bound.
	 */
	inline bool IsNullInterface(){
		return reference == 0x0;
	}

	/**
	 * \brief Get targeted interface
	 *
	 * \warning This method is used internally, you must not use it.
	 */
	inline AnInterfaceDescriptor* getReference(){
		return reference;
	}

};

}

#endif /* MINDCPP_IDL_INTERFACEREFERENCE_HPP_ */
