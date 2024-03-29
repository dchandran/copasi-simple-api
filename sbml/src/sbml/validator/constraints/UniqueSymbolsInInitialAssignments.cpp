/**
 * @cond doxygen-libsbml-internal
 *
 * @file    UniqueSymbolsInInitialAssignments.cpp
 * @brief   Ensures the ids for all UnitDefinitions in a Model are unique
 * @author  Ben Bornstein
 *
 * $Id: UniqueSymbolsInInitialAssignments.cpp 12784 2011-02-08 07:37:42Z mhucka $
 * $HeadURL: https://sbml.svn.sourceforge.net/svnroot/sbml/branches/libsbml-5/src/sbml/validator/constraints/UniqueSymbolsInInitialAssignments.cpp $
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2011 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <sbml/Model.h>
#include <sbml/UnitDefinition.h>

#include "UniqueSymbolsInInitialAssignments.h"

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

static const char* PREAMBLE =
    "A given identifier cannot appear as the value of more than one 'symbol' "
    "field across the set of <initialAssignment>s in a model. (References: "
    "L2V2 Section 4.10.)";


/**
 * Creates a new Constraint with the given constraint id.
 */
UniqueSymbolsInInitialAssignments::UniqueSymbolsInInitialAssignments ( unsigned int id,
                                                           Validator& v ) :
  UniqueIdBase(id, v)
{
}


/**
 * Destroys this Constraint.
 */
UniqueSymbolsInInitialAssignments::~UniqueSymbolsInInitialAssignments ()
{
}


/**
 * @return the preamble to use when logging constraint violations.
 */
const char*
UniqueSymbolsInInitialAssignments::getPreamble ()
{
  return PREAMBLE;
}


/**
 * Checks that all ids on UnitDefinitions are unique.
 */
void
UniqueSymbolsInInitialAssignments::doCheck (const Model& m)
{
  unsigned int n, size;


  size = m.getNumInitialAssignments();
  for (n = 0; n < size; ++n) checkId( *m.getInitialAssignment(n) );
}

LIBSBML_CPP_NAMESPACE_END

/** @endcond */
