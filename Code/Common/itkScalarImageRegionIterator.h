/*==========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkScalarImageRegionIterator.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.
  
==========================================================================*/
#ifndef __itkScalarImageRegionIterator_h
#define __itkScalarImageRegionIterator_h

#include "itkImageRegionIterator.h"
#include "itkPixelTraits.h"


namespace itk
{

/** \class ScalarImageRegionIterator
 * \brief Iterator that invokes GetScalar() on an image.
 *
 * ScalarImageRegionIterator is a templated class to represent a
 * multi-dimensional iterator. It is a specialized form of
 * ImageIterator that invokes the GetScalar() method. GetScalar() is
 * used when you want to write a filter that processes only the scalar
 * portion of a pixel.  
 */

template<class TImage>
class ScalarImageRegionIterator : 
public ImageRegionIterator<TImage>
{
public:
  /**
   * Standard "Self" typedef.
   */
  typedef ScalarImageRegionIterator  Self;
  
  /**
   * Standard "Superclass" typedef.
   */
  typedef ImageRegionIterator<TImage>  Superclass;

  /**
   * Dimension of the image the iterator walks.  This enum is needed so that
   * functions that are templated over image iterator type (as opposed to
   * being templated over pixel type and dimension) can have compile time
   * access to the dimension of the image that the iterator walks.
   */
  enum { ImageIteratorDimension = Superclass::ImageIteratorDimension };

  /** 
   * Index typedef support. While this was already typdef'ed in the superclass
   * it needs to be redone here for this subclass to compile properly with gcc.
   */
  typedef typename Superclass::IndexType IndexType;

  /** 
   * Size typedef support. While this was already typdef'ed in the superclass
   * it needs to be redone here for this subclass to compile properly with gcc.
   */
  typedef typename Superclass::SizeType SizeType;

  /** 
   * Region typedef support.
   */
  typedef typename Superclass::RegionType   RegionType;

  /**
   * Image typedef support. While this was already typdef'ed in the superclass
   * it needs to be redone here for this subclass to compile properly with gcc.
   */
  typedef typename Superclass::ImageType ImageType;

  /** 
   * PixelContainer typedef support. Used to refer to the container for
   * the pixel data. While this was already typdef'ed in the superclass
   * it needs to be redone here for this subclass to compile properly with gcc.
   */
  typedef typename Superclass::PixelContainer PixelContainer;
  typedef typename PixelContainer::Pointer PixelContainerPointer;

  /**
   * Internal Pixel Type
   */
  typedef typename Superclass::InternalPixelType   InternalPixelType;

  /**
   * External Pixel Type
   */
  typedef typename Superclass::PixelType   PixelType;

  /** 
   *  Accessor type that convert data between internal and external
   *  representations.
   */
  typedef typename Superclass::AccessorType     AccessorType;

  /** 
   * Run-time type information (and related methods).
   */
  itkTypeMacro(ScalarImageRegionIterator, ImageRegionIterator);

  /**
   * Default constructor. Needed since we provide a cast constructor.
   */
  ScalarImageRegionIterator()
    : ImageRegionIterator<TImage>() {}
  
  /**
   * Constructor establishes an iterator to walk a particular image and a
   * particular region of that image.
   */
  ScalarImageRegionIterator(ImageType *ptr,
                            const RegionType &region)
    : ImageRegionIterator<TImage>(ptr, region) {}

  /**
   * Constructor that can be used to cast from an ImageIterator to an
   * ScalarImageRegionIterator. Many routines return an ImageIterator but for a
   * particular task, you may want an ScalarImageRegionIterator.  Rather than
   * provide overloaded APIs that return different types of Iterators, itk
   * returns ImageIterators and uses constructors to cast from an
   * ImageIterator to a ScalarImageRegionIterator.
   */
  ScalarImageRegionIterator( const ImageIterator<TImage> &it)
    { this->ImageIterator<TImage>::operator=(it); }

  /**
   * Get the pixel value
   */
  typename ScalarTraits<PixelType>::ScalarValueType Get(void) const  
  { return ScalarTraits<PixelType>
      ::GetScalar(m_DataAccessor.Get(*(m_Buffer + m_Offset))); }
  
  /**
   * Set the pixel value
   */
  void Set( const ScalarTraits<PixelType>::ScalarValueType value) const  
  {
    PixelType p;
    ScalarTraits<PixelType>::SetScalar( p, value );
    m_DataAccessor.Set(*(m_Buffer + m_Offset), p);
  }

  
  /**
   * Define operator= for native types.
   */
//   void operator=(const typename TPixel::ScalarValueType v)
//     { 
//     }
  
  /**
   * Define operator= for native types.
   */
//   void operator=(const double v)
//     { 
//     }  
  
};


} // end namespace itk
  
#endif
