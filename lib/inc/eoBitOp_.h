// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

//-----------------------------------------------------------------------------
// eoBitOp.h
// (c) GeNeura Team, 2000 - EEAAX 2000 - Maarten Keijzer 2000
/*
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Contact: todos@geneura.ugr.es, http://geneura.ugr.es
             Marc.Schoenauer@polytechnique.fr
             mak@dhi.dk
 CVS Info: $Date: 2007-08-21 14:52:50 $ $Header: /home/nojhan/dev/eodev/eodev_cvs/eo/src/ga/eoBitOp.h,v 1.18 2007-08-21 14:52:50 kuepper Exp $ $Author: kuepper $
 */
//-----------------------------------------------------------------------------

#ifndef eoBitOp__h
#define eoBitOp__h

//-----------------------------------------------------------------------------

#include <algorithm>    // swap_ranges
#include <utils/eoRNG.h>
#include <eoInit.h>       // eoMonOp
#include <ga/eoBit.h>
#include <iostream>


/** eoNPtsBitXover --> n-point crossover
\class eoNPtsBitXover eoBitOp.h ga/eoBitOp.h
\ingroup bitstring
*/
template<class Chrom> class eoNPtsBitXoverCustom : public eoQuadOp<Chrom>
{
public:

    /** (Default) Constructor. */
    eoNPtsBitXoverCustom(const unsigned& _num_points = 2) : num_points(_num_points)
        {
            if (num_points < 1)
                std::runtime_error("NxOver --> invalid number of points");
        }

    /** The class name */
    virtual std::string className() const { return "eoNPtsBitXover"; }

    /** n-point crossover for binary chromosomes.

    @param chrom1 The first chromosome.
    @param chrom2 The first chromosome.
    */
    bool operator()(Chrom& chrom1, Chrom& chrom2) {
        unsigned max_size(std::min(chrom1.size(), chrom2.size()));
        unsigned max_points(std::min(max_size - 1, num_points));
        std::vector<bool> points(max_size, false);

        // select ranges of bits to swap
        do {
            unsigned bit(eo::rng.random(max_size));
            if(points[bit])
                continue;
            else {
                points[bit] = true;
                --max_points;
            }
        } while(max_points);

        // swap bits between chromosomes
        //bool change(false);
        //std::cout << "hhhh";
        unsigned int thestart = 0;
        unsigned int theend = chrom2.size();
        for (unsigned bit = 1; bit < points.size(); bit++) {

            if (points[bit] && thestart == 0 ){
             thestart = bit;
            }else if(points[bit] && thestart != 0 ){
             theend = bit;
         }
        }

      if(thestart % 2 ==0){
      }
      else{
        thestart = thestart + 1;
      }

      if(theend % 2 !=0){
      }
      else{
          theend = theend + 1; 
      }
      for (unsigned bit = thestart; bit <= theend; bit++) {
                typename Chrom::AtomType tmp = chrom1[bit];
                chrom1[bit] = chrom2[bit];
                chrom2[bit] = tmp;
            
       }
       return true;
    }

private:

    /** @todo Document this data member */
    unsigned num_points;
};





//-----------------------------------------------------------------------------
//@}
#endif
