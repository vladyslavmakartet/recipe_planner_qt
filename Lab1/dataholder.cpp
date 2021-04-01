#include "dataholder.h"

Recipe::Recipe(){}
Recipe::Recipe(const QString Name, const QString Description)//, QList<Ingredient> IngredientList)
{
    recipeName = Name;
    recipeDescription = Description;
    //ingredients = IngredientList;
}
QString Recipe::getRecipeName() const
{
    return this->recipeName;
}
QString Recipe::getRecipeDescription() const
{
    return this->recipeDescription;
}
void Recipe::setRecipeName(const QString Name)
{
    this->recipeName = Name;
}
void Recipe::setRecipeDescription(const QString Description)
{
    this->recipeDescription = Description;
}
Ingredient::Ingredient(){}
Ingredient::Ingredient(const QString newName, const qfloat16 newQuantity, const QString newUnit)
{
    name = newName;
    quantity = newQuantity;
    unit = newUnit;
}
QString Ingredient::getIngredientName() const
{
    return this->name;
}
qfloat16 Ingredient::getIngredientQuantity() const
{
    return this->quantity;
}
QString Ingredient::getIngredientUnit() const
{
    return this->unit;
}
void Ingredient::setIngredientName(const QString newName)
{
    this->name = newName;
}
void Ingredient::setIngredientQuantity(const qfloat16 newQuantity)
{
    this->quantity = newQuantity;
}
void Ingredient::setIngredientUnit(const QString newUnit)
{
    this->unit =newUnit;
}
