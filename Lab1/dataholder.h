#ifndef DATAHOLDER_H
#define DATAHOLDER_H
#include <qstring.h>
#include <QFloat16>
#include <QList>
class Recipe;
class Ingredient;

class Recipe
{
    QString recipeName;
    //QStringList recipeDescription;
    QString recipeDescription;
    QList<Ingredient> ingredients;
public:
    Recipe();
    Recipe(const QString Name, const QString Description);//, const QList<Ingredient>);
    QString getRecipeName() const;
    QString getRecipeDescription() const;
    void setRecipeName(const QString);
    void setRecipeDescription(const QString);
};


class Ingredient
{
    QString name;
    qfloat16 quantity;
    QString unit;
public:
    Ingredient();
    Ingredient(const QString name, const qfloat16 quantity, const QString unit);
    QString getIngredientName() const;
    qfloat16 getIngredientQuantity() const;
    QString getIngredientUnit() const;
    void setIngredientName(const QString);
    void setIngredientQuantity(const qfloat16);
    void setIngredientUnit(const QString);
};


#endif // DATAHOLDER_H
