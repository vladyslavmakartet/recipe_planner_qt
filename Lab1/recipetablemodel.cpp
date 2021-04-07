#include "recipetablemodel.h"

RecipeTableModel::RecipeTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}


RecipeTableModel::RecipeTableModel(const QVector<Recipe> &recipes, QObject *parent)
    : QAbstractTableModel(parent)
    , recipes(recipes)
{
}

QVariant RecipeTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role != Qt::DisplayRole)
        return QVariant();

    if (section == 0 && orientation == Qt::Horizontal) {
                return tr("Recipe");

        }

    if(orientation == Qt::Vertical)
        {
            return QString::number(section+1);
        }
    return QVariant();
}

bool RecipeTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {

        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int RecipeTableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : recipes.size();;

}

int RecipeTableModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 1;//3;
}

QVariant RecipeTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= recipes.size() || index.row() < 0)
        return QVariant();
    if (role == Qt::DisplayRole){
        const auto &recipe = recipes.at(index.row());


        if (index.column() == 0)
            return recipe.getRecipeName();
    }
    return QVariant();
}


bool RecipeTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        auto recipe = recipes.at(row);


        if(index.column() == 0)
            recipe.setRecipeName(value.toString());
        recipes.replace(row, recipe);
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }

    return false;
}

Qt::ItemFlags RecipeTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;


    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}



const QVector<Recipe> &RecipeTableModel::getRecipes() const
{
    return recipes;
}

bool RecipeTableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row)
        recipes.insert(position, {QString(), QString(), QVector<Ingredient>()});
    endInsertRows();
    return true;
}



bool RecipeTableModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row)
        recipes.removeAt(position);
    endRemoveRows();
    return true;
}































