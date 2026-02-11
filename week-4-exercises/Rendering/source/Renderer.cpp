#include "ImageUtils.h"
#include "Shapes.h"
#include <stddef.h>
#include <vector>
#include <memory>

void Render(Image &image, const std::vector<std::shared_ptr<Shape>> objects)
{
    // iterating over the image
    for(std::size_t px = 0; px < image.getWidth(); px++)
    {
        for(std::size_t py  = 0; py < image.getHeight(); py++)
        {
            // get centre of pixel
            double x = px+0.5, y = py+0.5;

            // implement your render logic here
        }
    }
}

int main()
{
    const std::size_t W = 200, H = 200;
    Image image(W, H);
    
    // set up your shapes here and then you can call Render

    image.Save("TestImage.pbm");
}