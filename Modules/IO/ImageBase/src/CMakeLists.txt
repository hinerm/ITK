set(ITKIOImageBase_SRC
itkArchetypeSeriesFileNames.cxx
itkImageIOFactory.cxx
itkIOCommon.cxx
itkNumericSeriesFileNames.cxx
itkImageIOBase.cxx
itkRegularExpressionSeriesFileNames.cxx
itkStreamingImageIOBase.cxx
)

add_library(ITKIOImageBase ${ITKIOImageBase_SRC})
target_link_libraries(ITKIOImageBase  ${ITKCommon_LIBRARIES})
itk_module_target(ITKIOImageBase)
