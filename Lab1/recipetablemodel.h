//#ifndef RECIPETABLEMODEL_H
//#define RECIPETABLEMODEL_H

//#include <QAbstractTableModel>
////#include "dataholder.h"
//#include <QMultiMap>
//struct Recipe
//{
//    QString recipeName;
//    QString recipeDescription;
//    //QMap<QString,QPair<qfloat16,QString>> ingredient;
//    //QMap<QString,QString> ingredient;
//    QMap<QString,QVariant> ingredient;
//    bool operator==(const Recipe &other) const
//    {
//        return  recipeName == other.recipeName && recipeDescription == other.recipeDescription;
//    }
//};
////typedef QMap<QString,QPair<qfloat16,QString>> ingredient;
////Q_DECLARE_METATYPE(ingredient);

//inline  QDataStream &operator<<(QDataStream &stream, const Recipe &recipe)
//{
//    return stream << recipe.recipeName << recipe.recipeDescription;
//}
//inline  QDataStream &operator>>(QDataStream &stream, Recipe &recipe)
//{
//    return stream >> recipe.recipeName >> recipe.recipeDescription;
//}

//class RecipeTableModel : public QAbstractTableModel
//{
//    Q_OBJECT

//public:
//    explicit RecipeTableModel(QObject *parent = nullptr);
//    explicit RecipeTableModel(const QList<Recipe> &recipes, QObject *parent = nullptr);

//    // Header:
//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

//    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

//    // Basic functionality:
//    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
//    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

//    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

//    // Editable:
//    bool setData(const QModelIndex &index, const QVariant &value,
//                 int role = Qt::EditRole) override;

//    Qt::ItemFlags flags(const QModelIndex& index) const override;

//    // Add data:
//    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
//    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

//    // Remove data:
//    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
//    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

//    const QVector<Recipe> &getRecipes() const;

//private:
//    QVector<Recipe> recipes;
//};

//#endif // RECIPETABLEMODEL_H
