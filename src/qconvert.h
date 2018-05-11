#ifndef QCONVERT_H
#define QCONVERT_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QStringListModel>
#include <QStringList>
#include <QListView>

namespace Ui
{
class QConvert;
}

class QConvert : public QMainWindow
{
    Q_OBJECT

public:
    explicit QConvert ( QWidget* parent = 0 );
    ~QConvert();

private:
    Ui::QConvert* ui;

    QMenu* qm_File, *qm_Info;
    QAction* qa_Quit, *qa_About, *qa_AboutQt;
    QComboBox* comboboxCategories;
    void createActions(), createMenus(), createUnitCategoriesList(), createUnitSelectionsList();
	QGridLayout* qgl_GridLayout, *grid_UnitCategories, *grid_UnitSelection, *grid_UnitConversion;
    QStringListModel* strListModel_categories, *strListModel_units_selection;
    QStringList list_of_units_Mechanics, list_of_UnitCategories;
    QListView* lst_CategoriesView, *lst_UnitsView_from, *lst_UnitsView_to;
    QGroupBox* qgb_GroupUnitCategories, *qgb_GroupToolBar, *qgb_UnitSelection, *qgb_UnitConversion;
    QGroupBox* createUnitCategoriesGpBox(), *createToolBarGpBox(), *createUnitSelectionGpBox(), *createUnitConversionGpBox();
    QPushButton* btnTime, *btnLength, *btnTemperature, *btnWeight, *btnSpeed, *btnSurface, *btnQuit;
    QLabel* label_UnitCategory, *label_input, *label_output;
    QLineEdit* lineEdit_input, *lineEdit_output;


private slots:
    void about();
    void aboutQt();
};

#endif // QCONVERT_H
