import torch
from tqdm.auto import tqdm
from typing import Dict, List, Tuple


def training_phase(model: torch.nn.Module,
                   dataloader: torch.utils.data.DataLoader,
                   loss_func: torch.nn.Module,
                   optimizer: torch.optim.Optimizer,):
    model.train()
    training_loss = 0

    for batch, (X, y) in enumerate(dataloader):
        y_pred = model(X)

        loss = loss_func(y_pred, y)
        training_loss += loss.item()

        optimizer.zero_grad()

        loss.backward()

        optimizer.step()

        y_pred_class = torch.argmax(torch.softmax(y_pred, dim=1), dim=1)

    training_loss /= len(dataloader)

    return training_loss


def test_phase(model: torch.nn.Module,
               dataloader: torch.utils.data.DataLoader,
               loss_func: torch.nn.Module,):
    model.eval()
    test_loss = 0

    with torch.inference_mode():
        for batch, (X, y) in enumerate(dataloader):
            test_pred_logits = model(X)

            loss = loss_func(test_pred_logits, y)
            test_loss += loss.item()

            test_pred_label = test_pred_logits.argmax(dim=1)

    test_loss /= len(dataloader)
    return test_loss


def train(model: torch.nn.Module,
          training_dataloader: torch.utils.data.DataLoader,
          test_dataloader: torch.utils.data.DataLoader,
          loss_func: torch.nn.Module,
          optimizer: torch.optim.Optimizer,
          epochs: int):
    results = {
        'training_loss': [],
        'test_loss': []
    }

    for epoch in tqdm(range(epochs)):
        training_loss = training_phase(model,
                                       training_dataloader,
                                       loss_func,
                                       optimizer)

        test_loss = test_phase(model,
                               test_dataloader,
                               loss_func)
        results['training_loss'].append(training_loss)
        results['test_loss'].append(test_loss)

        print(f'\nEpoch: {epoch},'
              f'Training Error: {training_loss:.4f},'
              f'Test Loss: {test_loss:.4f}')

    return results

