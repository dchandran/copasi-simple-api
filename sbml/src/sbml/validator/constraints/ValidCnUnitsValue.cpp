/**
 * @cond doxygen-libsbml-internal
 *
 * @file    ValidCnUnitsValue.cpp
 * @brief   Ensures units values are valid.
 * @author  Sarah Keating
 *
 * $Id: ValidCnUnitsValue.cpp 12784 2011-02-08 07:37:42Z mhucka $
 * $HeadURL: https://sbml.svn.sourceforge.net/svnroot/sbml/branches/libsbml-5/src/sbml/validator/constraints/ValidCnUnitsValue.cpp $
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
#include <sbml/Compartment.h>
#include <sbml/Species.h>
#include <sbml/Parameter.h>
#include <sbml/UnitDefinition.h>
#include <sbml/Event.h>
#include <sbml/Reaction.h>
#include <sbml/EventAssignment.h>
#include <sbml/SpeciesReference.h>
#include <sbml/Rule.h>
#include <sbml/math/FormulaFormatter.h>

#include <sbml/units/UnitFormulaFormatter.h>

#include "ValidCnUnitsValue.h"

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

static const char* PREAMBLE =
    "The arguments of the MathML logical operators 'and', 'or', 'xor', and "
    "'not' must have boolean values. (References: L2V2 Section 3.5.8.)";


/**
 * Creates a new Constraint with the given id.
 */
ValidCnUnitsValue::ValidCnUnitsValue (unsigned int id, Validator& v) : MathMLBase(id, v)
{
}


/**
 * Destroys this Constraint.
 */
ValidCnUnitsValue::~ValidCnUnitsValue ()
{
}


/**
 * @return the preamble to use when logging constraint violations.
 */
const char*
ValidCnUnitsValue::getPreamble ()
{
  return PREAMBLE;
}


/**
  * Checks the MathML of the ASTnode 
  * is appropriate for the function being performed
  *
  * If an inconsistency is found, an error message is logged.
  */
void
ValidCnUnitsValue::checkMath (const Model& m, const ASTNode& node, const SBase & sb)
{

  if (node.isNumber())
  {
    checkValidUnits(m, node, sb);
  }
  else
  {
    ASTNodeType_t type = node.getType();

    switch (type) 
    {
      case AST_FUNCTION:

        checkFunction(m, node, sb);
        break;

      default:

        checkChildren(m, node, sb);
        break;

    }
  }

  //switch (type) 
  //{
  //  case AST_LOGICAL_AND:
  //  case AST_LOGICAL_NOT:
  //  case AST_LOGICAL_OR:
  //  case AST_LOGICAL_XOR:

  //    checkMathFromLogical(m, node, sb);
  //    break;


  //  case AST_FUNCTION:

  //    checkFunction(m, node, sb);
  //    break;

  //  default:

  //    checkChildren(m, node, sb);
  //    break;

  //}
}

  
/**
  * Checks that the arguments to logical operators are all boolean
  *
  * If not, an error message is logged.
  */
void 
ValidCnUnitsValue::checkValidUnits (const Model& m, const ASTNode& node, 
                                                const SBase & sb)
{
  std::string units = node.getUnits();

  if (!units.empty())
  {
    if (!(Unit::isUnitKind(units, m.getLevel(), m.getVersion()))
      && (m.getUnitDefinition(units) == NULL))
    {
      logMathConflict(node, sb);
    }
  }
}


/**
 * @return the error message to use when logging constraint violations.
 * This method is called by logFailure.
 *
 * Returns a message that the given id and its corresponding object are
 * in  conflict with an object previously defined.
 */
const string
ValidCnUnitsValue::getMessage (const ASTNode& node, const SBase& object)
{

  ostringstream msg;


  return msg.str();
}

LIBSBML_CPP_NAMESPACE_END

/** @endcond */
