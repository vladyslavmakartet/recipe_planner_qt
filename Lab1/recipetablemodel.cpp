//#include "recipetablemodel.h"

//RecipeTableModel::RecipeTableModel(QObject *parent)
//    : QAbstractTableModel(parent)
//{
//}

//RecipeTableModel::RecipeTableModel(const QVector<Recipe> &recipes, QObject *parent)
//    : QAbstractTableModel(parent)
//    , recipes(recipes)
//{
//}

//QVariant RecipeTableModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//    if (role != Qt::DisplayRole)
//        return QVariant();

//    if (orientation == Qt::Horizontal) {
//        switch (section) {
//            case 0:
//                return tr("Recipe");
//            case 1:
//                return tr("Description");
//            case 2:
//                return tr("Ingredients");
//            default:
//                break;
//        }
//    }
//    return QVariant();
//}

//bool RecipeTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
//{
//    if (value != headerData(section, orientation, role)) {
//        // FIXME: Implement me!
//        emit headerDataChanged(orientation, section, section);
//        return true;
//    }
//    return false;
//}


//int RecipeTableModel::rowCount(const QModelIndex &parent) const
//{
//    return parent.isValid() ? 0 : recipes.size();;
//    // FIXME: Implement me!
//}

//int RecipeTableModel::columnCount(const QModelIndex &parent) const
//{
//    return parent.isValid() ? 0 : 3;
//}

//QVariant RecipeTableModel::data(const QModelIndex &index, int role) const
//{
//    if (!index.isValid())
//        return QVariant();
//    if (index.row() >= recipes.size() || index.row() < 0)
//        return QVariant();
//    if (role == Qt::DisplayRole){
//        const auto &recipe = recipes.at(index.row());

//        switch (index.column()) {
//            case 0:
//                return recipe.recipeName;
//            case 1:
//                return recipe.recipeDescription;
//            case 2:
//            //return QVariantList(recipe.ingredient)//recipe.ingredient;
//                return recipe.ingredient;
//        default:
//                break;
//        //else if (index.column() == 2)   // FIXME: Implement me!
//        //    return recipe.getRecipeIngredient();
//        }
//    }
//    return QVariant();
//}

////bool RecipeTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
////{
////    if (data(index, role) != value) {
////        // FIXME: Implement me!
////        emit dataChanged(index, index, QVector<int>() << role);
////        return true;
////    }
////    return false;
////}
//bool RecipeTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if (index.isValid() && role == Qt::EditRole) {
//        const int row = index.row();
//        auto recipe = recipes.value(row);

//        switch (index.column()) {
//            case 0:
//                recipe.recipeName = value.toString();
//                break;
//            case 1:
//                recipe.recipeDescription=value.toString();
//                break;/// to add ingredients
//            case 2:
//                recipe.ingredient=value.toMap();
//            break;
//            default:
//                return false;
//        }
//        recipes.replace(row, recipe);
//        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

//        return true;
//    }

//    return false;
//}

//Qt::ItemFlags RecipeTableModel::flags(const QModelIndex &index) const
//{
//    if (!index.isValid())
//        return Qt::ItemIsEnabled;


//    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
//}

////bool RecipeTableModel::insertRows(int row, int count, const QModelIndex &parent)
////{
////    beginInsertRows(parent, row, row + count - 1);
////    // FIXME: Implement me!
////    for (int row_ = 0; row_ < count; ++row_)

////        //recipes.insert(row,{ QString(), QString() });
////    endInsertRows();
////    return true;
////}

//const QVector<Recipe> &RecipeTableModel::getRecipes() const
//{
//    return recipes;
//}

//bool RecipeTableModel::insertRows(int row, int count, const QModelIndex &index)
//{
//    Q_UNUSED(index);
//    beginInsertRows(QModelIndex(), row, row + count - 1);
//    // FIXME: Implement me!
//    for (int row_ = 0; row_ < count; ++row_)
//        recipes.insert(row, { QString(), QString()});/////
//    endInsertRows();
//    return true;
//}

//bool RecipeTableModel::insertColumns(int column, int count, const QModelIndex &parent)
//{
//    beginInsertColumns(parent, column, column + count - 1);
//    // FIXME: Implement me!
//    endInsertColumns();
//}

//bool RecipeTableModel::removeRows(int row, int count, const QModelIndex &parent)
//{
//    beginRemoveRows(parent, row, row + count - 1);
//    for (int row_ = 0; row_ < count; ++row_)
//        recipes.removeAt(row);
//    // FIXME: Implement me!
//    endRemoveRows();
//    return true;
//}

//bool RecipeTableModel::removeColumns(int column, int count, const QModelIndex &parent)
//{
//    beginRemoveColumns(parent, column, column + count - 1);
//    // FIXME: Implement me!
//    endRemoveColumns();
//}
