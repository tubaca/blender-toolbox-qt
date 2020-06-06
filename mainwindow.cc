#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "toolbox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        Tool transformTool("Transform", QIcon (":/light_krita_tool_transform.svg"));
        Tool moveTool("Move", QIcon(":/light_krita_tool_move.svg"));
        Tool cropTool("Crop", QIcon (":/light_tool_crop.svg"));
        transformTool.addSubTool(moveTool);
        transformTool.addSubTool(cropTool);

        Tool shapeSelectTool("Shape Select", QIcon(":/light_select.svg"));
        Tool editShapesTool("Edit Shapes", QIcon(":/light_shape_handling.svg"));
        Tool textTool("Text", QIcon(":/light_draw-text.svg"));
        Tool calligraphyTool("Text", QIcon(":/light_calligraphy.svg"));
        shapeSelectTool.addSubTool(editShapesTool);
        shapeSelectTool.addSubTool(textTool);
        shapeSelectTool.addSubTool(calligraphyTool);

        Tool brushTool("Brush", QIcon(":/light_krita_tool_freehand.svg"));
        Tool dynamicBrushTool("Dynamic Brush", QIcon(":/light_krita_tool_dyna.svg"));
        Tool multiBrushTool("Multi Brush", QIcon(":/light_krita_tool_multihand.svg"));
        brushTool.addSubTool(dynamicBrushTool);
        brushTool.addSubTool(multiBrushTool);

        Tool fillTool("Fill", QIcon(":/light_krita_tool_color_fill.svg"));
        Tool colorPicker("Color Picker", QIcon(":/light_krita_tool_color_picker.svg"));
        Tool smartPatchTool("Smart Patch", QIcon(":/light_krita_tool_smart_patch.svg"));
        Tool gradientTool("Gradient", QIcon(":/light_krita_tool_gradient.svg"));
        fillTool.addSubTool(colorPicker);
        fillTool.addSubTool(smartPatchTool);
        fillTool.addSubTool(gradientTool);

        Tool rectangleTool("Rectangle", QIcon(":/light_krita_tool_rectangle.svg"));
        Tool lineTool("Line", QIcon(":/light_krita_tool_line.svg"));
        Tool freehandTool("Freehand", QIcon(":/light_krita_tool_freehandvector.svg"));
        Tool ellipseTool("Ellipse", QIcon(":/light_krita_tool_ellipse.svg"));
        Tool polylineTool("Polygon", QIcon(":/light_polyline.svg"));
        Tool pathTool("Path", QIcon(":/light_krita_draw_path.svg"));
        Tool lazyBrushTool("Lazy Brush", QIcon(":/light_krita_tool_lazybrush.svg"));
        rectangleTool.addSubTool(lineTool);
        rectangleTool.addSubTool(ellipseTool);
        rectangleTool.addSubTool(polylineTool);
        rectangleTool.addSubTool(freehandTool);
        rectangleTool.addSubTool(pathTool);
        rectangleTool.addSubTool(lazyBrushTool);

        Tool rectangularMarqueeTool("Rectangular Selection", QIcon (":/light_tool_rect_selection.svg"));
        Tool circularMarqueeTool("Elliptical Selection", QIcon (":/light_tool_elliptical_selection.svg"));
        Tool polygonalLasso("Polygonal Selection", QIcon(":/light_tool_polygonal_selection.svg"));
        Tool lassoTool("Freehand Selection", QIcon(":/light_tool_outline_selection.svg"));
        rectangularMarqueeTool.addSubTool(circularMarqueeTool);
        rectangularMarqueeTool.addSubTool(polygonalLasso);
        rectangularMarqueeTool.addSubTool(lassoTool);

        Tool contiguousSelectionTool("Contiguous Selection", QIcon(":/light_tool_contiguous_selection.svg"));
        Tool similarSelectionTool("Similar Selection", QIcon(":/light_tool_similar_selection.svg"));
        Tool magneticLasso("Magnetic Selection", QIcon(":/light_tool_magnetic_selection.svg"));
        Tool bezierCurveLasso("Path Selection", QIcon(":/light_tool_path_selection.svg"));
        contiguousSelectionTool.addSubTool(similarSelectionTool);
        contiguousSelectionTool.addSubTool(polygonalLasso);
        contiguousSelectionTool.addSubTool(magneticLasso);
        contiguousSelectionTool.addSubTool(bezierCurveLasso);

        Tool referenceImagesTool("Reference Images", QIcon(":/light_krita_tool_reference_images.svg"));
        Tool assistantTool("Assistants", QIcon(":/light_krita_tool_assistant.svg"));
        Tool measureTool("Measure", QIcon(":/light_krita_tool_measure.svg"));
        referenceImagesTool.addSubTool(assistantTool);
        referenceImagesTool.addSubTool(measureTool);

        Tool panTool("Pan", QIcon(":/light_tool_pan.svg"));
        Tool zoomTool("Zoom", QIcon(":/light_tool_zoom.svg"));
        panTool.addSubTool(zoomTool);

        ToolBox *tb = ui->widget;

        tb->addTool(transformTool);
        tb->addBreak();

        tb->addTool(shapeSelectTool);
        tb->addTool(brushTool);
        tb->addBreak();

        tb->addTool(fillTool);
        tb->addTool(rectangleTool);
        tb->addBreak();

        tb->addTool(rectangularMarqueeTool);
        tb->addTool(contiguousSelectionTool);
        tb->addBreak();

        tb->addTool(referenceImagesTool);
        tb->addTool(panTool);
        tb->addBreak();

}

MainWindow::~MainWindow()
{
    delete ui;
}

